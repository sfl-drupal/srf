<?php

/**
 * Callback function to alter titles of differents field widgets.
 * Types of fields:
 * - text,
 * - text_long,
 * - taxonomy_term_reference,
 * - date,
 * - link_field
 * @param array $element Element to be altered
 */
function srf_field_alter_widget(&$element) {
  $element['#title'] = theme('srf_field_label', array(
    'title' => $element['#title'],
  ));
}

/**
 * Callback function to alter text_with_summary widget.
 * @param array $element Element to be altered
 */
function srf_text_with_summary_alter_widget(&$element) {
  srf_field_alter_widget($element);
  $element['summary']['#title'] = theme('srf_field_label', array(
    'title' => $element['summary']['#title'],
  ));
}

/**
 * Callback function to alter entityreference widget.
 * @param array $element Element to be altered
 */
function srf_entityreference_alter_widget(&$element) {
  srf_field_alter_widget($element);
  $element['target_id']['#title'] = theme('srf_field_label', array(
    'title' => $element['target_id']['#title'],
  ));
}

/**
 * Callback function to alter file or image widget.
 * @param array $element Element to be altered
 */
function srf_file_alter_widget(&$element) {
  if (isset($element['#title'])) {
    srf_field_alter_widget($element);
  }
  else {
    foreach ($element as $id => &$elem) {
      if (isset($elem['#title'])) {
        srf_field_alter_widget($elem);
      }
    }
  }
}

/**
 * Callback function to alter email widget.
 * @param array $element Element to be altered
 */
function srf_email_alter_widget(&$element) {
  srf_field_alter_widget($element);
  $element['email']['#title'] = theme('srf_field_label', array(
    'title' => $element['email']['#title'],
  ));
}
